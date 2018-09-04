#!/bin/bash

set -ex

rsync -av --password-file=../rsyncd.secrets  ../codecomplete  root@192.168.199.135::share