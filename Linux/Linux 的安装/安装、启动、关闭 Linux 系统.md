<table>
    <tr>
        <td rowspan="2">syn</td> 
        <td colspan="2">把内存的数据同步到磁盘</td> 
   </tr>
    <tr>
  		<td colspan="2">我们在关机或者重启的时候，都应该先执行sync命令，把内存的数据写入磁盘，防止数据丢失</td> 
    </tr>
    <tr>
        <td rowspan="3">关机</td> 
        <td>shutdown-h now</td> 
        <td>表示立即关机</td>
    </tr>
    <tr>
        <td>shutdown-h 1</td>
        <td>表示一分钟后关机</td>
    </tr>
    <tr>
        <td>init 0 或halt</td>
        <td>就是直接使用，效果等价于关机</td>
    </tr>
</table>
