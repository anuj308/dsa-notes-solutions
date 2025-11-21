import React,{Component} from "react";

class LifeCycleDemo extends Component {
    constructor(){
        super();
        this.state = {count:0};
        console.log("1 constructor")
    }
    static getDerivedStateFromProps(){
        console.log("2 getDerivedStateFromProps")
        return null;
    }

    componentDidMount(){
        console.log("4 componentsDIDMount")
    }

    shouldComponentUpdate(){
        console.log("5 shouldcomponentupdate")
        return true;
    }

    getSnapshotBeforeUpdate(){
        console.log("6 getsnapshotbeforeupdate")
        return null;
    }

    componentDidUpdate(){
        console.log("7 componentDidUpdate")
    }
    componentWillUnmount(){
        console.log("8 component will un mount")
    }
    increment = ()=>{
        this.setState({count:this.state.count+1});
    }
    render(){
        console.log("3 Render")
        return (
            <>
            <h2>count {this.state.count}</h2>
            <button onClick={this.increment}>increment</button>
            </>
        )
    }
}


export default LifeCycleDemo
