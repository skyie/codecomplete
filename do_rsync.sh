#!/bin/bash

set -ex

#rsync -avz --password-file=../rsyncd.secrets  --include-from="include_file" --exclude="./*" ../codecomplete   root@192.168.199.135::share

rsync -avz --password-file=../rsyncd.secrets   ../codecomplete   root@192.168.199.135::share