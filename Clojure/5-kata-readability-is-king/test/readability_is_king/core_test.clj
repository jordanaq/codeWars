(ns readability-is-king.core-test
  (:require [clojure.test :refer :all]
            [readability-is-king.core :refer :all]))

(defn =? [a b] (= (format "%.2f" a) (format "%.2f" b)))

(def cases [
            [ "The turtle is leaving." 3.67]
            [ "A good book is hard to find." -1.06]
            [ "To be or not to be. That is the question." -0.66]
            [ "Oh no! The lemming is falling." 1.31]
            [ "Do not cut your fingers as your katana is getting sharper! Be gentle." 4.19]])

(deftest deterministic-tests
  (doseq [[text val] cases]
    (testing text (is (=? (flesch-kincaid text) val)))))