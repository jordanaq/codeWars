(ns persistent.core)

(defn persistence [n]
  (loop [n n, iter 0]
    (if (< n 10) iter
      (recur (apply * (map #(- 48 (int %)) (str n))) (inc iter)))))
