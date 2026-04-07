
<!-- for variable -->
{{$value}} 

@php

$name = "<h1>Coding</h1>";

@endphp
<!-- for html -->
{!!$name!!}
{{$name}}

<!-- 
@if($value=='1'){{'the value is 1'}}
@elseif($value=='2'){{'the value is 2'}}
@else{{'the value is not 1 or 2'}}
@endif -->

<!-- 
@php $i=0; @endphp

@while($i<10)
{{$i}}
@php $i++; @endphp
@endwhile

@php $i=0; @endphp
@while(++$i<=10)
{{$i}}
@endwhile -->

<!-- @php
$arr = ['a','b','c'];
@endphp

@foreach($arr as $val)
<h1>{{$val}}</h1>
@endforeach -->

<!-- so if the value is there then it will work otherwise it won't -->
<!-- @isset($value)
{{'Hello ' . $value}}
@endisset -->
<!-- unless is opposite of isset -->


