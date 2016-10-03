set ns [new Simulator]

set n0 [$ns node]
set n1 [$ns node]

set nf [open out.nam w]
$ns namtrace-all $nf 
set f [open out.tr w]
$ns trace-all $f 

$ns duplex-link $n0 $n1 0.2Mb 200ms DropTail
$ns duplex-link-op $n0 $n1 orient right
$ns queue-limit $n0 $n1 10

Agent/TCP set nam_tracevar_ true
set tcp [new Agent/TCP]
$tcp set windowInit_ 4
$tcp set maxcwnd_ 4

$ns attach-agent $n0 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink 

$ns connect $tcp $sink 

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns add-agent-trace $tcp tcp
$ns monitor-agent-trace $tcp
$tcp tracevar cwnd_ 

$ns at 0.1 "$ftp start"
$ns at 3.0 "$ns detach-agent $n0 $tcp ; $ns detach-agent $n1 $sink"
$ns at 3.5 "finish"

$ns at 0.0 "$ns trace-annotate \"Sliding Window with window size 4 (normal operation)\""

$ns at 0.05 "$ns trace-annotate \"FTP starts at 0.1\""

$ns at 0.56 "$ns trace-annotate \"Send Packet_0,1,2,3\""
$ns at 0.79 "$ns trace-annotate \"Receive Ack_0,1,2,3\""
$ns at 0.99 "$ns trace-annotate \"Send Packet_4,5,6,7\""
$ns at 1.23 "$ns trace-annotate \"Receive Ack_4,5,6,7\""
$ns at 1.43 "$ns trace-annotate \"Send Packet_8,9,10,11\""
$ns at 1.67 "$ns trace-annotate \"Receive Ack_8,9,10,11 \"" 
$ns at 1.88 "$ns trace-annotate \"Send Packet_12,13,14,15\""
$ns at 2.11 "$ns trace-annotate \"Receive Ack_12,13,14,15\""
$ns at 2.32 "$ns trace-annotate \"Send Packet_16,17,18,19\""
$ns at 2.56 "$ns trace-annotate \"Receive Ack_16,17,18,19\""
$ns at 2.76 "$ns trace-annotate \"Send Packet_20,21,22,23\""
$ns at 3.00 "$ns trace-annotate \"Receive Ack_23\""

$ns at 3.1 "$ns trace-annotate \"FTP stops\""










$ns duplex-link $n1 $n0 0.2Mb 200ms DropTail
$ns queue-limit $n1 $n0 10

Agent/TCP set nam_tracevar_ true
set tcp [new Agent/TCP]
$tcp set windowInit_ 4
$tcp set maxcwnd_ 4

$ns attach-agent $n1 $tcp

set sink [new Agent/TCPSink]
$ns attach-agent $n0 $sink 

$ns connect $tcp $sink 

set ftp [new Application/FTP]
$ftp attach-agent $tcp

$ns add-agent-trace $tcp tcp
$ns monitor-agent-trace $tcp
$tcp tracevar cwnd_ 

$ns at 0.1 "$ftp start"
$ns at 3.0 "$ns detach-agent $n1 $tcp ; $ns detach-agent $n0 $sink"
$ns at 3.5 "finish"

$ns at 0.0 "$ns trace-annotate \"Sliding Window with window size 4 (normal operation)\""

$ns at 0.05 "$ns trace-annotate \"FTP starts at 0.1\""

$ns at 0.56 "$ns trace-annotate \"Send Packet_0,1,2,3\""
$ns at 0.79 "$ns trace-annotate \"Receive Ack_0,1,2,3\""
$ns at 0.99 "$ns trace-annotate \"Send Packet_4,5,6,7\""
$ns at 1.23 "$ns trace-annotate \"Receive Ack_4,5,6,7\""
$ns at 1.43 "$ns trace-annotate \"Send Packet_8,9,10,11\""
$ns at 1.67 "$ns trace-annotate \"Receive Ack_8,9,10,11 \"" 
$ns at 1.88 "$ns trace-annotate \"Send Packet_12,13,14,15\""
$ns at 2.11 "$ns trace-annotate \"Receive Ack_12,13,14,15\""
$ns at 2.32 "$ns trace-annotate \"Send Packet_16,17,18,19\""
$ns at 2.56 "$ns trace-annotate \"Receive Ack_16,17,18,19\""
$ns at 2.76 "$ns trace-annotate \"Send Packet_20,21,22,23\""
$ns at 3.00 "$ns trace-annotate \"Receive Ack_23\""

$ns at 3.1 "$ns trace-annotate \"FTP stops\"" 












proc finish {} {

	global ns
	$ns flush-trace

	# puts "filtering..."
	exec tclsh ../ns-allinone-2.35/nam-1.15/bin/namfilter.tcl out.nam
	puts "running nam..."
	exec nam out.nam &
	exit 0
}

$ns run
