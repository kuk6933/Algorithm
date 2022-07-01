<html>
<head>
<title>main.cpp</title>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
.s0 { color: #c586a1;}
.s1 { color: #d4d4d4;}
.s2 { color: #cd9069;}
.s3 { color: #499cd5;}
.s4 { color: #b4cda8;}
.s5 { color: #699856;}
</style>
</head>
<body bgcolor="#1e1e1e">
<table CELLSPACING=0 CELLPADDING=5 COLS=1 WIDTH="100%" BGCOLOR="#606060" >
<tr><td><center>
<font face="Arial, Helvetica" color="#000000">
main.cpp</font>
</center></td></tr></table>
<pre><span class="s0">#include </span><span class="s2">&lt;string&gt;</span>
<span class="s0">#include </span><span class="s2">&lt;vector&gt;</span>

<span class="s3">using namespace </span><span class="s1">std;</span>

<span class="s1">vector&lt;</span><span class="s3">int</span><span class="s1">&gt; solution(vector&lt;</span><span class="s3">int</span><span class="s1">&gt; lottos, vector&lt;</span><span class="s3">int</span><span class="s1">&gt; win_nums) {</span>
    <span class="s1">vector&lt;</span><span class="s3">int</span><span class="s1">&gt; answer;</span>
    <span class="s3">int </span><span class="s1">zero_cnt=</span><span class="s4">0</span><span class="s1">;</span>
    <span class="s3">for</span><span class="s1">(</span><span class="s3">int </span><span class="s1">i=</span><span class="s4">0</span><span class="s1">; i&lt; lottos.size(); i++)</span>
    <span class="s1">{</span>
        <span class="s3">if</span><span class="s1">(lottos[i]==</span><span class="s4">0</span><span class="s1">)</span>
        <span class="s1">{</span>
            <span class="s1">zero_cnt++; </span><span class="s5">//0 개수 count</span>
        <span class="s1">}</span>
    <span class="s1">}</span>
    <span class="s3">int </span><span class="s1">match=</span><span class="s4">0</span><span class="s1">;</span>

    <span class="s3">for</span><span class="s1">(</span><span class="s3">int </span><span class="s1">i=</span><span class="s4">0</span><span class="s1">; i&lt;lottos.size(); i++)</span>
    <span class="s1">{</span>
        <span class="s3">for</span><span class="s1">(</span><span class="s3">int </span><span class="s1">j=</span><span class="s4">0</span><span class="s1">; j&lt;win_nums.size(); j++)</span>
        <span class="s1">{</span>
            <span class="s3">if</span><span class="s1">(lottos[i]==win_nums[j])</span>
            <span class="s1">{</span>
                <span class="s1">match++; </span><span class="s5">//0제외하고 일치하는 개수 count</span>
                <span class="s3">break</span><span class="s1">;</span>
            <span class="s1">}</span>
        <span class="s1">}</span>
    <span class="s1">}</span>
    <span class="s3">int </span><span class="s1">high= match+zero_cnt; </span><span class="s5">// high는 0이 모두 일치+ 원래 일치하는경우</span>
    <span class="s3">int </span><span class="s1">low= match; </span><span class="s5">//0이 일치하지 않는 경우</span>
    <span class="s3">switch</span><span class="s1">(high)</span>
    <span class="s1">{</span>
        <span class="s3">case </span><span class="s4">6</span><span class="s1">: answer.push_back(</span><span class="s4">1</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">5</span><span class="s1">: answer.push_back(</span><span class="s4">2</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">4</span><span class="s1">: answer.push_back(</span><span class="s4">3</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">3</span><span class="s1">: answer.push_back(</span><span class="s4">4</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">2</span><span class="s1">: answer.push_back(</span><span class="s4">5</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">default</span><span class="s1">: answer.push_back(</span><span class="s4">6</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
    <span class="s1">}</span>

    <span class="s3">switch</span><span class="s1">(low)</span>
    <span class="s1">{</span>
        <span class="s3">case </span><span class="s4">6</span><span class="s1">: answer.push_back(</span><span class="s4">1</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">5</span><span class="s1">: answer.push_back(</span><span class="s4">2</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">4</span><span class="s1">: answer.push_back(</span><span class="s4">3</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">3</span><span class="s1">: answer.push_back(</span><span class="s4">4</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">case </span><span class="s4">2</span><span class="s1">: answer.push_back(</span><span class="s4">5</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
        <span class="s3">default</span><span class="s1">: answer.push_back(</span><span class="s4">6</span><span class="s1">); </span><span class="s3">break</span><span class="s1">;</span>
    <span class="s1">}</span>

    <span class="s3">return </span><span class="s1">answer;</span>
<span class="s1">}</span></pre>
</body>
</html>