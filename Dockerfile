# Ubuntu 20.04 (focal)
# https://hub.docker.com/_/ubuntu/?tab=tags&name=focal
# OS/ARCH: linux/amd64
#FROM ubuntu:focal-20201106@sha256:4e4bc990609ed865e07afc8427c30ffdddca5153fd4e82c20d8f0783a291e241
FROM jupyter/base-notebook:latest

USER root

# Install jupyter notebook
RUN apt-get update \
   && apt-get -y upgrade \
   && apt-get -y --no-install-recommends install jupyter-notebook python3-pip g++ make ccache gdb

RUN pip install numpy pandas scikit-learn matplotlib
RUN pip install ipywidgets widgetsnbextension plotly optuna 
RUN pip install networkx
RUN pip install mip
RUN pip install graphviz pydotplus

# Jupyter notebook hashed password
## $ python3
## >>> from notebook.auth import passwd
## >>> passwd()
#
# or enter this docker container,
#
# $ docker run --rm -it jupyter_base
# 
# run the following script in the container,
#
# $ python3 scripts/pass.py
ARG JUPYTER_PASSWD='sha1:ad8c4d398f17:a36cce35eb85c12e438abcf5f44e35b161105a01'

# User name
#ARG NB_USER='jovyan'

# Add user
#ARG NB_UID="1000"
#RUN useradd -m -s /bin/bash -N -u $NB_UID $NB_USER

#USER $NB_UID
#WORKDIR /home/$NB_USER

# Copy the scripts for hash password and notebook server config.
#COPY ./scripts /home/jovya/scripts

# Generate a notebook server config
#RUN jupyter notebook -y --generate-config
#RUN ./scripts/notebook_config.sh $JUPYTER_PASSWD

# working directory
#RUN mkdir work
WORKDIR /home/jovyan/work

# Port
EXPOSE 8888

