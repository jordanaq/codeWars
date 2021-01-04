(ns josephusurvivor.core)

(defn josephus-survivor [n k]
  (if (= 1 n) 1
    (inc (mod (+ (dec k) (josephus-survivor (dec n) k)) n))))
