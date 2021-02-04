(ns readability-is-king.core
  (:require [clojure.string :as s]))

(defn flesch-kincaid [text]
  (let [wordNum (count (s/split text #"[ ]"))
        sentNum (count (s/split text #"[.!?]"))
        sylNum (count (filter #(not (s/blank? %)) (s/split (s/lower-case text) #"[bcdfghjklmnpqrstvwxz -A]")))]
    (+ (* 0.39 (/ wordNum sentNum)) (* 11.8 (/ sylNum wordNum)) -15.59)))