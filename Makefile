#
# $FML: Makefile,v 1.1 2024/02/13 01:28:51 fukachan Exp $
#

VERSION != cat etc/version

all: book-ebook book-print do-clean
book-ebook: do-book-ebook
book-print: do-book-print

init:
	@ test -d release || mkdir -p release
	@ cp -pv etc/config-starter.yml config-starter.yml
	@ sed "s|@VERSION@|${VERSION}|" etc/config.yml > config.yml.new
	@ mv -v config.yml.new config.yml

do-book-ebook: do-50-cmd-build
	@ make init
	@ cp -pv etc/catalog.yml.ebook catalog.yml
	@ docker run --rm -v `pwd -P`:/work -w /work kauplan/review2.5 rake pdf
	@ mv -v selected-unix-commands.pdf release/selected-unix-commands.ebook.${VERSION}.pdf
	@ make do-chown

do-book-print:
	@ make init
	@ cp -pv etc/catalog.yml.print catalog.yml
	@ docker run --rm -v `pwd -P`:/work -w /work kauplan/review2.5 rake pdf
	@ mv -v selected-unix-commands.pdf release/selected-unix-commands.print.${VERSION}.pdf
	@ make do-chown

do-chown:
	@ sudo chown `id -u`:`id -g` release/selected-unix-commands.*.pdf


do-50-cmd-build: contents/*.re
	@ sh utils/50-cmd-build.sh

do-clean:
	@ rm -fv config.yml catalog.yml config-starter.yml

clean: do-clean
	@ find . -name '*~' -delete -print
