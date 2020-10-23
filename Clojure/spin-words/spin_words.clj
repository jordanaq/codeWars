(ns spin-words
  (:require [clojure.string :as str]))

(defn spin-words [strng]
  (reduce (fn [x y] (str x " " y)) (map
                                     (fn [x]
                                       (if (>= (count x) 5)
                                         (str/reverse x)
                                          x))
                                     (str/split strng #" "))))
