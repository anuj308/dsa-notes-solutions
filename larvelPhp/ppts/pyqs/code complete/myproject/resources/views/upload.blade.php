<!DOCTYPE html>
<html>
<head>
    <title>File Upload</title>
</head>
<body>

    <h2>Upload File</h2>

    <!-- Show success message -->
    @if(session('success'))
        <p style="color:green;">{{ session('success') }}</p>
    @endif

    <!-- Show error -->
    @if($errors->any())
        <p style="color:red;">{{ $errors->first() }}</p>
    @endif

    <!-- Upload Form -->
    <form action="{{ route('file.upload') }}" method="POST" enctype="multipart/form-data">
        @csrf

        <input type="file" name="file">
        <br><br>

        <button type="submit">Upload</button>
    </form>

    <!-- Show uploaded file -->
    @if(session('file'))
        <h3>Uploaded File:</h3>

        <img src="{{ asset('storage/' . session('file')) }}" width="200">

        <p>
            <a href="{{ asset('storage/' . session('file')) }}" target="_blank">
                View File
            </a>
        </p>
    @endif

</body>
</html>