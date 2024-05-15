# flexric-dev
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

### Docker Compose Deployment
To deployment RIC, CU and DU with Docker Compose, run to following commands:

```sh
cd deployments
docker compose up -d
```

### QMAI-xApp Deployment

TODO