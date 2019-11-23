(ns dda.filter-plugin-test
  (:require 
    [clojure.test :refer :all]
    [dda.filter-plugin :as sut]))

(deftest test-filter-flat
  (testing      
    (is (= 1
           (count (sut/filter-sidebar '({})))
           ))
    (is (= 1
           (count (sut/filter-sidebar '({:other true})))
           ))
    (is (= 1
           (count (sut/filter-sidebar '({:navbar? false})))
           ))
     (is (= 0
           (count (sut/filter-sidebar '({:navbar? true})))
           ))
    ))
