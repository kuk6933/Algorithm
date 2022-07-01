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
<span class="s0">#include </span><span class="s2">&lt;iostream&gt;</span>

<span class="s3">using namespace </span><span class="s1">std;</span>

<span class="s1">string solution(string new_id) {</span>
    <span class="s1">string answer = </span><span class="s2">&quot;&quot;</span><span class="s1">;</span>

    <span class="s3">for </span><span class="s1">(</span><span class="s3">int </span><span class="s1">i = </span><span class="s4">0</span><span class="s1">; i &lt; new_id.size(); i++) </span><span class="s5">//1단계</span>
    <span class="s1">{</span>
        <span class="s3">if </span><span class="s1">(new_id[i] &gt;= </span><span class="s4">65 </span><span class="s1">&amp;&amp; new_id[i] &lt;= </span><span class="s4">90</span><span class="s1">) {</span>
            <span class="s1">new_id[i] += </span><span class="s4">32</span><span class="s1">;</span>
        <span class="s1">}</span>
    <span class="s1">}</span>

    <span class="s3">for </span><span class="s1">(</span><span class="s3">int </span><span class="s1">i = </span><span class="s4">0</span><span class="s1">; i &lt; new_id.size(); i++) </span><span class="s5">//2단계</span>
    <span class="s1">{</span>
        <span class="s3">if </span><span class="s1">(!(new_id[i] &gt;= </span><span class="s4">97 </span><span class="s1">&amp;&amp; new_id[i] &lt;= </span><span class="s4">122</span><span class="s1">)) </span><span class="s5">//alphabet아니고</span>
        <span class="s1">{</span>
            <span class="s3">if </span><span class="s1">(!(new_id[i] &gt;= </span><span class="s4">48 </span><span class="s1">&amp;&amp; new_id[i] &lt;= </span><span class="s4">57</span><span class="s1">)) </span><span class="s5">// 숫자도 아니고</span>

                <span class="s3">if </span><span class="s1">(new_id[i] != </span><span class="s2">'-' </span><span class="s1">&amp;&amp; new_id[i] != </span><span class="s2">'_' </span><span class="s1">&amp;&amp; new_id[i] != </span><span class="s2">'.'</span><span class="s1">) {</span>
                    <span class="s1">new_id.erase(i, </span><span class="s4">1</span><span class="s1">);</span>
                    <span class="s1">i--;</span>
                <span class="s1">}</span>
        <span class="s1">}</span>
    <span class="s1">}</span>
    <span class="s3">int </span><span class="s1">cnt = </span><span class="s4">0</span><span class="s1">;</span>
    <span class="s3">for </span><span class="s1">(</span><span class="s3">int </span><span class="s1">i = </span><span class="s4">0</span><span class="s1">; i &lt; new_id.size(); i++) </span><span class="s5">//3단계</span>
    <span class="s1">{</span>
        <span class="s3">if </span><span class="s1">(new_id[i] == </span><span class="s2">'.'</span><span class="s1">) {</span>
            <span class="s1">cnt++;</span>
            <span class="s3">if </span><span class="s1">(cnt &gt;= </span><span class="s4">2</span><span class="s1">) {</span>
                <span class="s1">new_id.erase(i, </span><span class="s4">1</span><span class="s1">);</span>
                <span class="s1">cnt--;</span>
                <span class="s1">i--;</span>
            <span class="s1">}</span>
        <span class="s1">}</span>
        <span class="s3">else</span>
        <span class="s1">{</span>
           <span class="s1">cnt=</span><span class="s4">0</span><span class="s1">;</span>
        <span class="s1">}</span>
    <span class="s1">}</span>
    <span class="s3">if </span><span class="s1">(new_id[</span><span class="s4">0</span><span class="s1">] == </span><span class="s2">'.'</span><span class="s1">)  </span><span class="s5">//4단계</span>
    <span class="s1">{</span>
        <span class="s1">new_id.erase(</span><span class="s4">0</span><span class="s1">, </span><span class="s4">1</span><span class="s1">);</span>
    <span class="s1">}</span>
    <span class="s3">if </span><span class="s1">(new_id[new_id.size() - </span><span class="s4">1</span><span class="s1">] == </span><span class="s2">'.'</span><span class="s1">) </span><span class="s5">//4단계</span>
    <span class="s1">{</span>
        <span class="s1">new_id.erase(new_id.size() - </span><span class="s4">1</span><span class="s1">, </span><span class="s4">1</span><span class="s1">);</span>
    <span class="s1">}</span>
    <span class="s3">if </span><span class="s1">(new_id.size() == </span><span class="s4">0</span><span class="s1">) </span><span class="s5">//5단계</span>
    <span class="s1">{</span>
        <span class="s1">new_id = </span><span class="s2">&quot;a&quot;</span><span class="s1">;</span>
    <span class="s1">}</span>



    <span class="s3">if </span><span class="s1">(new_id.size() &gt;= </span><span class="s4">16</span><span class="s1">)</span><span class="s5">//6단계</span>
    <span class="s1">{</span>
        <span class="s1">new_id.erase(</span><span class="s4">15</span><span class="s1">,new_id.size()-</span><span class="s4">15</span><span class="s1">);</span>
        <span class="s3">if </span><span class="s1">(new_id[</span><span class="s4">0</span><span class="s1">] == </span><span class="s2">'.'</span><span class="s1">)</span>
        <span class="s1">{</span>
            <span class="s1">new_id.erase(</span><span class="s4">0</span><span class="s1">, </span><span class="s4">1</span><span class="s1">);</span>
        <span class="s1">}</span>
        <span class="s3">if </span><span class="s1">(new_id[new_id.size() - </span><span class="s4">1</span><span class="s1">] == </span><span class="s2">'.'</span><span class="s1">)</span>
        <span class="s1">{</span>
            <span class="s1">new_id.erase(new_id.size() - </span><span class="s4">1</span><span class="s1">, </span><span class="s4">1</span><span class="s1">);</span>
        <span class="s1">}</span>
    <span class="s1">}</span>

    <span class="s3">while</span><span class="s1">(new_id.size()&lt;=</span><span class="s4">2</span><span class="s1">)</span>
    <span class="s1">{</span>
        <span class="s1">new_id += new_id[new_id.size()-</span><span class="s4">1</span><span class="s1">];</span>
    <span class="s1">}</span>
    <span class="s1">answer = new_id;</span>

    <span class="s3">return </span><span class="s1">answer;</span>
<span class="s1">}</span>

<span class="s3">int </span><span class="s1">main()</span>
<span class="s1">{</span>
   <span class="s1">string str=</span><span class="s2">&quot;...!@BaT#*..y.abcdefghijklm&quot;</span><span class="s1">;</span>
   <span class="s1">string a = solution(str);</span>
   <span class="s1">cout&lt;&lt;a;</span>
<span class="s1">}</span></pre>
</body>
</html>