#!/usr/bin/env perl

use strict;
use warnings;
use Carp;
use utf8;
use Encode;

our $debug   = $ENV{ debug } ? 1 : 0;
our $u_star  = "\x{203B}"; # hoshi
our $in_list = 0;

#
# MAIN
#
printf(STDERR "// handle %s\n", encode("UTF-8", $u_star)) if $debug;

my $queued = "";

 LINE:
    while (my $buf = <>) {
	$buf = decode("UTF-8", $buf);
	
	if ($buf =~ m|//list|) {
	    print STDERR "// START $buf\n" if $debug;
	    $in_list = 1;
	}
	elsif ($buf =~ m|^//\}|) {
	    print STDERR "// END $buf\n"   if $debug;
	    $in_list = 0;
	    do_print($buf);
	    do_print($queued) if $queued;
	    $queued = "";
	    next LINE;
	}

	if ($in_list) {
	    if ($buf =~ /^\s*$u_star(.*)/) {
		$queued .= $1;
		next LINE;
	    }
	}
	elsif ($debug > 2) {
	    if ($buf =~ /^\s*$u_star(.*)/) {
		$buf = $1;
	    }
	}

	# useful conversion
	if ($buf =~ /^===\s+/) {
	    $buf =~ s/オプション一覧/知っていると便利なオプション/;
	}
	if ($buf =~ /^====|^=====/) {
	    $buf =~ s/^==== /=== /;
	    $buf =~ s/^===== /==== /;
	}

	do_print($buf);
}

exit 0;

sub do_print
{
    my ($buf) = @_;
    
    print encode("UTF-8", $buf);

    unless ($buf =~ /\n$/) {
	print "\n";
    }
}
