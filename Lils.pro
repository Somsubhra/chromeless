TEMPLATE = subdirs

zlib.subdir = third-party/zlib

quazip.subdir = third-party/quazip
quazip.depends = zlib

app.subdir = app
app.depends = quazip

SUBDIRS = app quazip zlib