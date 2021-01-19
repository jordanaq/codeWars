(ns mixin.core)
(require '[clojure.string :as str])

(defn mix [s1 s2]
  (let [lowers (map char (range 97 123))
        nums (fn [s] (into (sorted-map) (sort-by second > (filterv #(> (second %) 1) (map #(vector % (count (filter #{%} s))) lowers)))))
        a (nums s1)
        b (nums s2)
        c (merge-with #(if (> %1 %2) %1 %2) a b)]
    (do (def res "")
      (doseq [x c]
        (if (= (get a (first x)) (get b (first x)))
          (def res (str res \= \: (apply str (repeat (second x) (first x))) \/))
          (if (= (get a (first x)) (second x))
            (def res (str res \1 \: (apply str (repeat (second x) (first x))) \/))
            (def res (str res \2 \: (apply str (repeat (second x) (first x))) \/)))))
      (if (empty? res) "" (subs res 0 (dec (count res)))))))
