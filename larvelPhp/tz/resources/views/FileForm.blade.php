<div>
    <form method="POST" action="upload" enctype="multipart/form-data">
        @csrf
        <div>upload</div>
        <input type="file" name="file" required>
        <button type="submit">Upload</button>
    </form>
</div>
