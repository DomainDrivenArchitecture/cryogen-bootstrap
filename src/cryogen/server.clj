(ns cryogen.server
  (:require [compojure.core :refer [GET defroutes]]
            [compojure.route :as route]
            [ring.util.response :refer [redirect resource-response]]
            [ring.util.codec :refer [url-decode]]
            [cryogen-core.watcher :refer [start-watcher!]]
            [cryogen-core.plugins :refer [load-plugins]]
            [cryogen-core.compiler :refer [compile-assets-timed read-config]]
            [cryogen-core.io :refer [path]]))

(defn init []
  (load-plugins)
  (compile-assets-timed)
  (let [ignored-files (-> (read-config) :ignored-files)]
    (start-watcher! "resources/templates" ignored-files compile-assets-timed)))

(defn wrap-subdirectories
  [handler]
  (fn [request]
    (let [req-uri (.substring (url-decode (:uri request)) 1)
          res-path (path req-uri (when (:clean-urls? (read-config)) "index.html"))]
      (or (resource-response res-path {:root "public"})
          (handler request)))))

(defroutes routes
  (GET "/" [] (redirect (let [config (read-config)]
                          (path (:blog-prefix config) "/"
                                (when-not (:clean-urls? config) "index.html")))))
  (route/resources "/")
  (route/not-found "Page not found"))

(def handler (wrap-subdirectories routes))

;the following 2 function will create scripts for:
; checkout repository
; cronjob for pulling from repository and copying to document root
(defn pull-script-setup
  [document-root user repository-url git-directory source-files-location]
  (let [copy-command (str "cp -pr " git-directory source-files-location " " document-root)]
    ["#!/bin/bash"
    (str "git clone -C " git-directory " " repository-url)
    (str "echo " (str "0 * * * * " user " " "git pull -C " repository-url) " && " copy-command " > /etc/crontab")
    ]
  ))

;(defn pull-script-setup-stevedore
;  [document-root user repository-url git-directory source-files-location]
;  (let [copy-command (str "cp -pr " git-directory source-files-location " " document-root)]
;    (stevedore/with-script-language :pallet.stevedore.bash/bash
;        (stevedore/with-source-line-comments false 
;          (stevedore/script
;            ("git clone -C" ~git-directory ~repository-url)
;            (str "echo " (str "0 * * * * " ~user " " "git pull -C " ~repository-url) " && " ~copy-command " > /etc/crontab")
;                     )))))
