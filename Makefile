filter:
	grep 'Len=[0-9]' stream -o > o_len
	cat stream | awk '{print $3}' > o_source
	paste o_source o_len > o_merge


