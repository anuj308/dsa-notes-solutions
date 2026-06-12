<h2>Contact Form</h2>
<form method="POST" action="/contact">
    @csrf
    Name: <input type="text" name="name"><br><br>
    Email: <input type="email" name="email"><br><br>
    Message:<br>
    <textarea name="message"></textarea><br><br>
3
<button type="submit">Submit</button>
</form>