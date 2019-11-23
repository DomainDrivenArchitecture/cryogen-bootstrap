(defproject dda/cryogen-bootstrap "0.1.0-SNAPSHOT"
  :description "bootstrap theme for cryogen"
  :license {:name "Apache2.0"}
  :dependencies [[org.clojure/clojure "1.9.0"]
                 [ring/ring-devel "1.7.1"]
                 [compojure "1.6.1"]
                 [ring-server "0.5.0"]
                 [dda/cryogen-core "0.1.53"]
                 [dda/cryogen-markdown "0.1.6"]]
  :repositories [["clojars" :clojars]]
  :deploy-repositories [["clojars" :clojars]])
