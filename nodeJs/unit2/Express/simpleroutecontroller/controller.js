export const userController=(req, res)=>{
    const name = req.params.name;
    res.send("welcome to user page " +name);
}

export const aboutController =(req, res)=>{
    const name = req.params.name;
    res.send("welcome to about page " +name);
}
export const loginController = (req, res)=>{
    const name = req.params.name;
    res.send("logged In  " +name);
}

export const logoutController = (req, res)=>{
    const name = req.params.name;
    res.send("logout " +name);
}