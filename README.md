# FlexRIC Dev
xApp development environment using Near-RT FlexRIC from the Mosaic5G project

## Requirements

- make;
- Docker (20.10 or newer);
-

## Get Starting

### Building Docker Images
To build the RIC, CU and DU Docker images, run to following command:

```sh
make docker-build-all
```

### Only Near-RT FlexRIC deployment

```sh
docker container run -tid --name flexric -p 36421:36421/sctp -p 36422:36422 --restart on-failure muriloavlis/flexric:dev
```

### RIC deployment with emulated CU and DU
To deployment RIC, CU and DU with Docker Compose, run to following commands:

```sh
cd deployments
docker compose up -d
```

### xApp Deployment

TODO