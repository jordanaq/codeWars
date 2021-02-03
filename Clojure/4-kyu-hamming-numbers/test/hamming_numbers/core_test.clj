(ns hamming-numbers.core-test
  (:require [clojure.test :refer :all]
            [hamming-numbers.core :refer :all]))

(def hams [1 2 3 4 5 6 8 9 10 12 15 16 18 20 24 25 27 30 32 36])

(deftest first-20
  (doseq [n (range 20) :let [ham (nth hams n)]]
    (is (= ham (hamming n)))))
