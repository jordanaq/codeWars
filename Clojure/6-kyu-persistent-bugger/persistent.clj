(ns persistent.core)

(defn persistence [n]
  (loop [n n, iter 0]
    (if (< n 10) iter
      (recur (apply * (map #(- (int %) 48) (str n))) (inc iter)))))
