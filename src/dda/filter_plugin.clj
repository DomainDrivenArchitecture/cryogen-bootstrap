(ns dda.filter-plugin
  (:require
    [selmer.filters :as filters]
    [clojure.string :as s]))

(defn filter-feature [pages]
  (let [result (filter #(:feature? %) pages)]
    (sort-by :page-index result)))

(defn filter-navbar [pages]
  (let [result (filter #(:navbar? %) pages)]
    (sort-by :page-index result)))

(defn filter-sidebar [pages]
  (let [result (filter #(not (:navbar? %)) pages)]
    (sort-by :page-index result)))

(defn filter-even [number]
  (even? number))

(defn init []
  (filters/add-filter! "filter-feature" filter-feature)
  (filters/add-filter! "filter-navbar" filter-navbar)
  (filters/add-filter! "filter-sidebar" filter-sidebar)
  (filters/add-filter! "even?" filter-even))
