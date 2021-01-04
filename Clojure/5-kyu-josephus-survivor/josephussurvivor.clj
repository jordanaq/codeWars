(ns josephusurvivor.core)

(defn josephus-survivor [n k]
  (loop [n n, k k, pos #(inc (mod (dec %) n))]
    (if (= 1 n) (pos 1)
      (recur (dec n) k (comp pos #(inc (mod (+ (dec k) %) n)))))))
