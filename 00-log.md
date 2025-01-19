# v2.0.0 post produnction memo

## working branches

ブランチ名が適当すぎるので、まずブランチ名を修正。
renameするとgithub側の修正が面倒かつクリティカルなので、
エイリアスを切った（つまりブランチ名のコピーを行った）。
ブランチ名は v2-draft-post-production == v2-draft == test となっている。

ポストプロダクションとレビューの作業は v2-draft-post-production ブランチで行い、
せめて v2.0.0-rc1 くらいになった段階で main ブランチへマージする予定

```
$ git branch
  main
  test
  v2-draft
* v2-draft-post-production
```


## contents/ clean up

見づらいので、v1.0.0 のファイル群は contents/v1/ へ移動した。
v2 のファイルも最終的には contents 直下へ移動したいが、
とりあえず今の「contents/ユーザ名/コマンド.re」のまま作業を行うことにする。
どのみち、ファイル群から contents/20-selected-commands.re を合成するので、どちらにあってもよい
（注：合成するスクリプトは utils/v2-aggregate-files.sh）。


## コンテンツの構成

etc/catalog.yml.print.v2 の定義のとおり。
前述のとおり、20-selected-commands.re は、ビルド時に自動生成するが、
それ以外のファイル（下記のファイル）群（00-preface.re, 10-unix-cli-overview.re, 99-postscript.re）は手動編集

```
[catalog.yml.print.v2]

PREDEF:
  - 00-preface.re

## 本文
CHAPS:
  - 10-unix-cli-overview.re
  - 20-selected-commands.re
  
## 付録
APPENDIX:

## あとがき
POSTDEF:
  - 99-postscript.re
```

