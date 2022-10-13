import React, { useEffect, useState } from "react";
const App = () => {
  const [celsius, setCelsius] = useState(0);
  const [findFahrenheit, setFindFahrenheit] = useState(0);
  const [fahrenheit, setFahrenheit] = useState(0);
  const [findCelsius, setFindCelsius] = useState(0);

  const inputChange = (e,type) =>{
    console.log(e.key)
    let value = e.target.value
    if(type=='cel'){
      setCelsius(value)
    } else if(type=="far"){
      setFahrenheit(value)
    }
  }


  const convertFaran = () => {
    const calFahren = (celsius * 9 / 5) + 32;
    setFindFahrenheit(calFahren);
  }

  const convertCel = () => {
    const calFahren = (fahrenheit - 32) * 5 / 9;
    setFindCelsius(calFahren);
  }

  useEffect(() => {
    convertFaran();
  }, [celsius])
  useEffect(() => {
    convertCel();
  }, [fahrenheit])

  return (
    <main className="container">
      <h1 className="title">Temperature Converter</h1>
      <section className="column">
        <label className="column--title">Enter the Celsius</label>
        <section className="column__left">
          <input className="column--input" defaultValue={celsius} onChange={(e) => inputChange(e, 'cel')} />
          <span>=</span>
          <p className="column--output">{findFahrenheit}</p>
        </section>

        <button className="column--btn bn28" onClick={() => setCelsius(0)}>Clear</button>

      </section>
      <section className="column">
        <label className="column--title">Enter the Fahrenheit</label>
        <section className="column__right">
          <input className="column--input" defaultValue={fahrenheit} onChange={(e) => inputChange(e, 'far')}  />
          <span>=</span>
          <p className="column--output">{findCelsius.toFixed(2)}</p>
        </section>

        <button className="column--btn bn28" onClick={() => setFahrenheit(0)}>Clear</button>

      </section>
    </main>
  )
};

export default App;