(defproject dda/cryogen-bootstrap "0.1.1-SNAPSHOT"
  :description "bootstrap theme for cryogen"
  :url "https://domaindrivenarchitecture.org"
  :license {:name "Apache License, Version 2.0"
            :url "https://www.apache.org/licenses/LICENSE-2.0.html"}
  :dependencies [[org.clojure/clojure "1.8.0"]
                 [ring/ring-devel "1.7.1"]
                 [compojure "1.6.1"]
                 [ring-server "0.5.0"]
                 [dda/cryogen-core "0.2.0-SNAPSHOT"]
                 [dda/cryogen-markdown "0.1.6"]]
  :repositories [["snapshots" :clojars]
                 ["releases" :clojars]]
  :deploy-repositories [["snapshots" :clojars]
                        ["releases" :clojars]]
  :source-paths ["src"]
  :resource-paths ["resources"]
  :profiles {:dev {:source-paths ["test"]
                   :resource-paths ["test-resources"]
                   :dependencies []
                   :leiningen/reply
                   {:dependencies [[org.slf4j/jcl-over-slf4j "1.8.0-beta0"]]
                    :exclusions [commons-logging]}}
             :test {:source-paths ["test"]
                    :resource-paths ["test-resources"]
                    :dependencies []}})
