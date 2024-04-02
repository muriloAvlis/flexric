help: # TODO


build-all: build-flexric build-flexric-gnb-cu build-flexric-gnb-du

build-flexric:
	docker image build -t muriloavlis/flexric:dev -f docker/Dockerfile.flexric.ubuntu .

build-flexric-gnb-cu:
	docker image build -t muriloavlis/flexric-gnb-cu:dev --build-arg NEAR_RIC_IP=192.168.122.20 -f docker/Dockerfile.gnb-cu.ubuntu .

build-flexric-gnb-du:
	docker image build -t muriloavlis/flexric-gnb-du:dev --build-arg NEAR_RIC_IP=192.168.122.20 -f docker/Dockerfile.gnb-du.ubuntu .

run-flexric:
	docker container run -d -it --name flexric -p 36421:36421/sctp -p 36422:36422/sctp muriloavlis/flexric:dev

run-flexric-gnb-cu:
	docker container run -d -it --name flexric-gnb-cu muriloavlis/flexric-gnb-cu:dev

run-flexric-gnb-du:
	docker container run -d -it --name flexric-gnb-du muriloavlis/flexric-gnb-du:dev

ric-logs:
	docker logs -f flexric

run-all: run-flexric run-flexric-gnb-cu run-flexric-gnb-du

clean-all:
	docker container rm -f flexric
	docker container rm -f flexric-gnb-cu
	docker container rm -f flexric-gnb-du
