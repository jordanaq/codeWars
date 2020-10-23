(ns digital-root)

(defn sum-digs [n]
	(loop [j n, res 0]
		(if (>= j 10)
			(recur (long (/ j 10)) (+ res (mod j 10)))
			(+ res j)
		)
	)
)

(defn digital-root [n]
	(if (>= n 10)
		(recur (sum-digs n))
		n
    )
)
