<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Email Form</title>
    <style>
        body {
            font-family: sans-serif;
            max-width: 720px;
            margin: 2rem auto;
            padding: 0 1rem;
        }
        .field {
            margin-bottom: 1rem;
        }
        label {
            display: block;
            margin-bottom: 0.4rem;
            font-weight: 600;
        }
        input, textarea {
            width: 100%;
            padding: 0.6rem;
            border: 1px solid #ccc;
            border-radius: 6px;
            box-sizing: border-box;
        }
        button {
            background: #1a73e8;
            color: #fff;
            border: 0;
            padding: 0.65rem 1.2rem;
            border-radius: 6px;
            cursor: pointer;
        }
        .ok {
            background: #e7f8ee;
            color: #166534;
            padding: 0.7rem;
            border-radius: 6px;
            margin-bottom: 1rem;
        }
        .err {
            background: #fef2f2;
            color: #991b1b;
            padding: 0.7rem;
            border-radius: 6px;
            margin-bottom: 1rem;
        }
    </style>
</head>
<body>
    <h1>Send Email</h1>

    @if (session('success'))
        <div class="ok">{{ session('success') }}</div>
    @endif

    @if ($errors->any())
        <div class="err">
            <ul>
                @foreach ($errors->all() as $error)
                    <li>{{ $error }}</li>
                @endforeach
            </ul>
        </div>
    @endif

    <form method="POST" action="{{ route('email.send') }}">
        @csrf

        <div class="field">
            <label for="to">To (email)</label>
            <input id="to" name="to" type="email" value="{{ old('to') }}" required>
        </div>

        <div class="field">
            <label for="sub">Subject</label>
            <input id="sub" name="sub" type="text" value="{{ old('sub') }}" required>
        </div>

        <div class="field">
            <label for="msg">Message</label>
            <textarea id="msg" name="msg" rows="6" required>{{ old('msg') }}</textarea>
        </div>

        <button type="submit">Send</button>
    </form>
</body>
</html>
