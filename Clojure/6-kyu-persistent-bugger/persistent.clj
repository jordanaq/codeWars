(ns persistent.core)

(defn persistence [n]
  (loop [n n, iter 0]
    (if (< n 10) iter
      (recur (reduce #(+ (- (int %1) 48) (- (int %2) 48)) (str n)) (inc iter)))))
