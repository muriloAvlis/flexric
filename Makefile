
## Includes
include ./MakefileVars.mk

.PHONY: docker-build-all

##@ Utility
help: ## Show this help.
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m\033[0m\n"} /^[a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

docker-build-all: docker-build-flexric docker-build-flexric-gnb-cu docker-build-flexric-gnb-du

docker-build-flexric:
	docker image build -t muriloavlis/flexric:dev -f docker/Dockerfile.flexric.ubuntu .

docker-build-flexric-gnb-cu:
	docker image build -t muriloavlis/flexric-gnb-cu:dev --build-arg NEAR_RIC_IP=${NEAR_RIC_IP} -f docker/Dockerfile.gnb-cu.ubuntu .

docker-build-flexric-gnb-du:
	docker image build -t muriloavlis/flexric-gnb-du:dev --build-arg NEAR_RIC_IP=${NEAR_RIC_IP} -f docker/Dockerfile.gnb-du.ubuntu .

docker-run-flexric:
	docker container run -d -it --name flexric -p 36421:36421/sctp -p 36422:36422/sctp muriloavlis/flexric:dev

docker-run-flexric-gnb-cu:
	docker container run -d -it --name flexric-gnb-cu muriloavlis/flexric-gnb-cu:dev

docker-run-flexric-gnb-du:
	docker container run -d -it --name flexric-gnb-du muriloavlis/flexric-gnb-du:dev

ric-logs:
	docker logs -f flexric

gnb-cu-logs:
	docker logs -f flexric-gnb-cu

gnb-du-logs:
	docker logs -f flexric-gnb-cu

docker-run-all: docker-run-flexric docker-run-flexric-gnb-cu docker-run-flexric-gnb-du

clean-all:
	docker container rm -f flexric
	docker container rm -f flexric-gnb-cu
	docker container rm -f flexric-gnb-du
