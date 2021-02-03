(ns largest-difference.core-test
  (:require [clojure.test :refer :all]
            [largest-difference.core :refer :all]))

(deftest a-test
  (testing "FIXME, I fail."
    (is (= 4 (largestDifference [9 4 1 10 3 4 0 -1 -2])))
    (is (= 0 (largestDifference [3 2 1])))))
