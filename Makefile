
## Includes
include ./makefileVars.mk

.PHONY: docker-build-all

##@ Utility
help: ## Show this help.
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make \033[36m\033[0m\n"} /^[a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

docker-build-all: docker-build-flexric docker-build-flexric-gnb-cu docker-build-flexric-gnb-du ## Build all FlexRIC docker images (RIC-CU-DU)

docker-build-flexric: ## Build FlexRIC docker image
	@echo "Building FlexRIC..."
	@docker image build -t muriloavlis/flexric:dev -f docker/Dockerfile.flexric.ubuntu .

docker-build-flexric-gnb-cu: ## Build FlexRIC-CU docker image
	@echo "Building FlexRIC-gNB-CU..."
	@docker image build -t muriloavlis/flexric-gnb-cu:dev --build-arg NEAR_RIC_IP=${NEAR_RIC_IP} -f docker/Dockerfile.gnb-cu.ubuntu .

docker-build-flexric-gnb-du: ## Build FlexRIC-DU docker image
	@echo "Building gNB-DU..."
	@docker image build -t muriloavlis/flexric-gnb-du:dev --build-arg NEAR_RIC_IP=${NEAR_RIC_IP} -f docker/Dockerfile.gnb-du.ubuntu .

docker-run-flexric: ## Run FlexRIC on Docker
	@echo "Running FlexRIC on Docker..."
	@docker container run -d -it --name flexric -p 36421:36421/sctp -p 36422:36422/sctp muriloavlis/flexric:dev

docker-run-flexric-gnb-cu: ## Run FlexRIC-gNB-CU on Docker
	@echo "Running FlexRIC-gNB-CU on Docker..."
	@docker container run -d -it --name flexric-gnb-cu muriloavlis/flexric-gnb-cu:dev

docker-run-flexric-gnb-du: ## Run FlexRIC-gNB-DU on Docker
	@echo "Running FlexRIC-gNB-DU on Docker..."
	@docker container run -d -it --name flexric-gnb-du muriloavlis/flexric-gnb-du:dev

docker-run-all: docker-run-flexric docker-run-flexric-gnb-cu docker-run-flexric-gnb-du ## Run FlexRIC stack on Docker (RIC-CU-DU)

docker-login: ## Logging into Docker Hub
	@echo "Logging into Docker Hub with user: ${DOCKER_USER}"
	@docker login -u ${DOCKER_USER}

docker-push-all: ## Push images to Docker Hub
	@echo "Pushing images to Docker Hub..."
	@docker image push muriloavlis/flexric:dev
	@docker image push muriloavlis/flexric-gnb-cu:dev
	@docker image push muriloavlis/flexric-gnb-du:dev

ric-logs: ## Get FlexRIC logs
	@docker logs -f flexric

gnb-cu-logs: ## Get FlexRIC-gNB-CU logs
	@docker logs -f flexric-gnb-cu

gnb-du-logs: ## Get FlexRIC-gNB-DU logs
	@docker logs -f flexric-gnb-cu


clean-all: ## Delete all FlexRIC containers on Docker
	echo "Deleting containers from Docker..."
	@docker container rm -f flexric
	@docker container rm -f flexric-gnb-cu
	@docker container rm -f flexric-gnb-du
