<?php

namespace App\Http\Middleware;

use Closure;
use Illuminate\Http\Request;
use Symfony\Component\HttpFoundation\Response;

class CheckRole
{
    public function handle(Request $request, Closure $next): Response
    {
        if ($request->role != "admin")
        {
            return response("Only Admin Can Access");
        }

        return $next($request);
    }
}