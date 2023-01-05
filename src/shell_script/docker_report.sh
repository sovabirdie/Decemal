#!bin/bash

if [ -d ~/goinfre ] 
then
    mkdir -p ~/goinfre/Docker/Data
    ln -s ~/goinfre/Docker ~/Library/Containers/com.docker.docker
else
    echo start
fi

docker ps
if [ $? -eq 1 ]
then
    echo please RUN docker
else
    docker rmi -f s21/docker_lcov_test
    docker rm docker_lcov_report
    docker   build . -t s21/docker_lcov_test -f docker/Dockerfile
    docker run --name docker_lcov_report -v $(pwd)/lcov_report:/project/lcov_report -it -e GOAL=$1 -e G=$2   s21/docker_lcov_test
    docker rmi -f s21/docker_lcov_test
    docker rm docker_lcov_report
fi