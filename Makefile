all:
	docker build . -t tak0kada/docker_command_template
	chmod 755 ./main

clean:
	docker image rm tak0kada/docker_command_template
