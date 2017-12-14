#!/usr/bin/perl
#c08ex7.cgi - pattern matching 
use strict;

#declare @items1 array
my @items1 = ("Carol Johnson", "45", "John Lawrence", "23%", "Sue Jones", "25",
	      "sue Pammers", "9", "Joan Williams", "3.3", "Pam", "\$7");

#Single characters and digits
#print "#1:\n"; foreach my $x (@items1) {if ($x =~ m/Jo.n/) {print "$x\n";}}    #1
#print "#2:\n"; foreach my $x (@items1) {if ($x =~ m/[Ss]ue/) {print "$x\n";}}  #2
#print "#3:\n"; foreach my $x (@items1) {if ($x =~ m/[^0-9]/) {print "$x\n";}}  #3
#print "#4:\n"; foreach my $x (@items1) {if ($x =~ m/\d\d/) {print "$x\n";}}    #4
#print "#5:\n"; foreach my $x (@items1) {if ($x =~ m/\D/) {print "$x\n";}}      #5
#print "#6:\n"; foreach my $x (@items1) {if ($x =~ m/Pam\w/) {print "$x\n";}}   #6
#print "#7:\n"; foreach my $x (@items1) {if ($x =~ m/\W/) {print "$x\n";}}      #7

#----------------------------------------------------------------------------------
#declare @items2 array
my @items2 = ("Sue Jones", "\tCarol", "Paul", "Peter\r", "Penny\n", "Jenny");

#Whitespace characters
#print "#8:\n"; foreach my $x (@items2) {if ($x =~ m/\s/) {print "$x\n";}}    #8
#print "#9:\n"; foreach my $x (@items2) {if ($x =~ m/\S/) {print "$x\n";}}    #9
#print "#10:\n"; foreach my $x (@items2) {if ($x =~ m/\n/) {print "$x\n";}}   #10
#print "#11:\n"; foreach my $x (@items2) {if ($x =~ m/\r/) {print "$x\n";}}   #11
#print "#12:\n"; foreach my $x (@items2) {if ($x =~ m/\t/) {print "$x\n";}}   #12

#----------------------------------------------------------------------------------
#declare @items3 array
my @items3 = ("Harry", "Drew", "Suman Drewson", 
	      "Sandra", "Carol Smith", "Jason Drew", "Mark O'Drew");

#Anchored characters
#print "#13:\n"; foreach my $x (@items3) {if ($x =~ m/Drew\b/) {print "$x\n";}} #13
#print "#14:\n"; foreach my $x (@items3) {if ($x =~ m/Drew\B/) {print "$x\n";}} #14
#print "#15:\n"; foreach my $x (@items3) {if ($x =~ m/^Drew/) {print "$x\n";}}  #15
#print "#16:\n"; foreach my $x (@items3) {if ($x =~ m/Drew$/) {print "$x\n";}}  #16

#----------------------------------------------------------------------------------
#declare @items4 array
my @items4 = ("fileexp.htm", "budexp1.html", "exp11.h", "emp111.ht", "file1111.html");

#Repeated characters
#print "#17:\n"; foreach my $x (@items4) {if ($x =~ m/html?/) {print "$x\n";}}     #17
#print "#18:\n"; foreach my $x (@items4) {if ($x =~ m/[0-9]*/) {print "$x\n";}}    #18
#print "#19:\n"; foreach my $x (@items4) {if ($x =~ m/[0-9]+/) {print "$x\n";}}    #19
#print "#20:\n"; foreach my $x (@items4) {if ($x =~ m/1{3,4}/) {print "$x\n";}}    #20
#print "#21:\n"; foreach my $x (@items4) {if ($x =~ m/^emp|^exp/) {print "$x\n";}} #21
