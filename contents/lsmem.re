#@# 

=={lsmem} lsmem

オンライン状態になっている利用可能なメモリの範囲をリスト表示できる。

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

#@# X-TODO lsmem table の場所
//table[lsmem][lsmemの読み方]{
項目			説明
------------------------------------------------------------
RANGE			メモリのアドレス範囲(これは1GBを示している。)
Memory block size	1ブロック当たりのサイズ(1GB/8=128MB)
Total online memory	使用可能なメモリサイズ(1GB)
Total offline memory	使用不可能なメモリサイズ(このメモリはすべて利用できる)
//}
