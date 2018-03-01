filter:
	cat stream | awk '{print $$2}' | sed -e 's/\.[0-9,]*$$//g' > o_time
	grep 'Len=[0-9]*' stream -o | grep '[0-9]*' -o > o_len
	cat stream | awk '{print $$3}' > o_addr
	paste o_time o_addr o_len > o_origin

run:
	grep '192.' o_origin | awk '{print $$1 " " $$3}' | grep -v 302 > o_source
	./main
	mv filtered o_src_client
	grep '160.' o_origin | awk '{print $$1 " " $$3}' | grep -v 302 > o_source
	./main
	mv filtered o_src_server

get_result:
	grep '192.168' filtered | awk '{print $$1 $$3}' > o_src_client
	grep '160.' filtered | awk '{print $$1 $$3}' > o_src_server

