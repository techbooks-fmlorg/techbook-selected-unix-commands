#@# 

=={lsmem} @<term>{lsmem}

(オンライン状態になっている)
メイン@<idx>{メモリ<<>>の利用可能な範囲を表示((のりようかのうなはんいをひょうじ))}する。

=== 書式

//list[][][fontsize=xx-small]{
$ lsmem [options]
//}
たいていはオプション無しで実行して良い

=== 実行例

==== 実行例

//list[][][fontsize=xx-small]{
$ lsmem
//}

==== 実行結果

//list[][][fontsize=xx-small]{
RANGE                                 SIZE  STATE REMOVABLE BLOCK
0x0000000000000000-0x000000003fffffff   1G online       yes   0-7

Memory block size:       128M
Total online memory:       1G
Total offline memory:      0B
//}
実用上はサイズの確認くらいだろう。
@<table>{lsmem}も参照のこと。

#@# X-TODO lsmem table の位置調整 (DEFERRED)
//table[lsmem][lsmemの読み方]{
項目			説明
------------------------------------------------------------
RANGE			メモリのアドレス範囲(この例では1GBを示している)
Memory block size	1ブロック当たりのサイズ(1GB/8=128MB)
Total online memory	使用可能な(オンラインの)メモリサイズ(例：1GB)
Total offline memory	使用不可能な（現在オフライン@<fn>{offine-memory}の）メモリサイズ
//}


//footnote[offine-memory][オフラインとは？メモリをブロック単位でオンライン/オフラインを設定できるのだが、超巨大な仮想基盤でもないかぎり使う機会のない機能に思える。詳細は@<href>{https://www.kernel.org/pub/linux/utils/util-linux/}の@<term>{chmem}のマニュアルとソースコードを参照したほうがよい]
