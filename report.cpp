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
<pre><span class="s0">#include </span><span class="s2">&lt;iostream&gt;</span>
<span class="s0">#include </span><span class="s2">&lt;string&gt;</span>
<span class="s0">#include </span><span class="s2">&lt;set&gt;</span>
<span class="s0">#include </span><span class="s2">&lt;map&gt;</span>
<span class="s0">#include </span><span class="s2">&lt;vector&gt;</span>
<span class="s0">#include </span><span class="s2">&lt;sstream&gt;</span>
<span class="s3">using namespace </span><span class="s1">std;</span>

<span class="s1">vector&lt;</span><span class="s3">int</span><span class="s1">&gt; solution(vector&lt;string&gt; id_list, vector&lt;string&gt; report, </span><span class="s3">int </span><span class="s1">k) {</span>
    <span class="s1">vector&lt;</span><span class="s3">int</span><span class="s1">&gt; answer;</span>
    <span class="s1">answer.resize(id_list.size(),</span><span class="s4">0</span><span class="s1">); </span><span class="s5">//answer 초기화</span>
    <span class="s1">map&lt;string,</span><span class="s3">int</span><span class="s1">&gt; id_map; </span><span class="s5">//id의 index를 매칭시키기 위한 map</span>
    <span class="s1">map&lt;string,set&lt;string&gt;&gt; reported; </span><span class="s5">//first를 신고한사람을 second set에 넣음</span>

    <span class="s3">for</span><span class="s1">(</span><span class="s3">int </span><span class="s1">i=</span><span class="s4">0</span><span class="s1">; i&lt;id_list.size(); i++)</span>
    <span class="s1">{</span>
        <span class="s1">id_map[id_list[i]]=i; </span><span class="s5">//매칭작업</span>
    <span class="s1">}</span>
    <span class="s1">string from, to; </span><span class="s5">// from이 to를 report</span>

    <span class="s3">for</span><span class="s1">(</span><span class="s3">auto </span><span class="s1">r: report )</span>
    <span class="s1">{</span>
        <span class="s1">stringstream ss(r); </span><span class="s5">//공백을 두고 신고인과 피신고인이 구별됨</span>
        <span class="s1">ss &gt;&gt; from&gt;&gt; to;</span>
        <span class="s1">reported[to].insert(from); </span><span class="s5">//신고인을 기준으로 신고한사람을 set에 삽입</span>
    <span class="s1">}</span>

    <span class="s3">for</span><span class="s1">(</span><span class="s3">auto </span><span class="s1">r: reported)</span>
    <span class="s1">{</span>
        <span class="s3">if</span><span class="s1">(r.second.size() &gt;=k) </span><span class="s5">//신고한 사람의 수가 k보다 많으면</span>
        <span class="s1">{</span>
            <span class="s3">for</span><span class="s1">(</span><span class="s3">auto </span><span class="s1">reporter: r.second)</span>
            <span class="s1">{</span>
                <span class="s1">answer[id_map[reporter]]++; </span><span class="s5">//신고한 사람이 메일 수를 1씩 증가시킴</span>
            <span class="s1">}</span>
        <span class="s1">}</span>

    <span class="s1">}</span>
    <span class="s3">return </span><span class="s1">answer;</span>
<span class="s1">}</span>
</pre>
</body>
</html>