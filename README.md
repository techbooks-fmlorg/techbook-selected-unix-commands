# 厳選Unixコマンド - Selected Unix Commands for Beginners -

- 第1版 v1.0.0 (2024/02/29 発行) ; 開発コード: 〜 公立千歳科学技術大学ITインフラ部へようこそ 〜
- 第2版 v2.0.0 (2025/02/28 発行) ; 開発コード: 〜 届けたいコマンド 〜
    - [v2.0.0 {レビュー,組版}作業ログ](log/v2.0.0.md)

## このリポジトリの使い方(作成方法)

[Re:VIEWスターターキット](https://kauplan.org/reviewstarter/)をベースにした原稿と、
その組版システムになっています。
Re:VIEWの使い方は
[Re:VIEW Starter ユーザーズガイド version 1.0 (PDF,2021/07/05)](https://kauplan.org/reviewstarter/reviewstarter-usersguide-20210715.pdf)
を熟読してください

### 原稿の書き方

contents/ 以下に原稿を書きます。
コマンドごとにファイルを分けて1コマンド1節(section)で書いてください。
ファイル名はコマンド名です。

印刷版での原稿の並びや章節の組立て方はetc/catalog.yml.printを編集します。
電子版は章を自動生成しています(必要であればMakefileとutils以下を調整してください)

前書き(contents/00-preface.re)と後書き(contents/99-postscript.re)は直接編集あるのみです。
表紙(images/cover_a5.pdf)も直接編集あるのみです。



### PDFの作成方法

make と docker コマンドが使える環境で実行してください。これは大前提です

```
$ make
```

Makefileの中にルールとしてビルド方法が定義されています。
ルールを改造したいなら、Makefileと`utils/`以下のスクリプトを調整してください

印刷版と電子版をそれぞれ作成するモードがあります。
ビルド時にetc/以下から必要な設定ファイルをコピーして使っています。
設定ファイルの変更をしたい場合はetc/以下を編集してください


### 生成物

うまくビルドできれば、`release/`以下にPDFファイルが生成されます。

```
release/selected-unix-commands.ebook.1.0.0.pdf
release/selected-unix-commands.print.1.0.0.pdf
```
このようにバージョン番号つきのファイル名になっていて、
拡張子.ebookが電子版、拡張子.printが印刷版です

バージョン名はsemantic versioningに従ってください



## リポジトリの構成

```
# github pages として公開するコンテンツ置き場

.
├── docs

# ビルドで使うルール(Makefile)とスクリプト(utils)
.
├── Makefile
└── utils

# 設定ファイル(ファイルの意味はRe:VIEWのマニュアルを参照)

.
├── etc
│   ├── catalog.yml.ebook     電子版のカタログ
│   ├── catalog.yml.print     印刷版のカタログ
│   ├── config-starter.yml
│   ├── config.yml            設定ファイル
│   └── version               バージョン番号


# 以下はRe:VIEW starter kitに由来するディレクトリ
.
├── contents   原稿(.re)を置く
├── css
├── data
├── images     原稿に入れる画像などを置く
├── layouts
├── lib
├── sty

```


## リファレンス


### Re:VIEW スターターキット

Re:VIEW 2.5をベースに本家とは分岐して開発されているもの。
[設定支援のウエブサイト](https://kauplan.org/reviewstarter/)が秀逸だし、
dockerイメージも配布されていて使いやすいので、
初心者は、これが良いと思う

- https://kauplan.org/reviewstarter/
    - ここから始めてください
- [技術系同人誌を書く人の味方「Re:VIEW Starter」の紹介 (qiita,2019)](https://qiita.com/kauplan/items/d01e6e39a05be0b908a1)
    - まとめ記事 (開発サイドが書いた記事で、決定版)
- [Re:VIEW Starter ユーザーズガイド version 1.0 (PDF,2021/07/05)](https://kauplan.org/reviewstarter/reviewstarter-usersguide-20210715.pdf)
    - こちらが詳細な解説書(PDF,272ページ)
    - これが、そもそも技術同人誌として配布されています(GJ!)
