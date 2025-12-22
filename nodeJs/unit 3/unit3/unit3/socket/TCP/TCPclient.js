


import net from 'net';

const client = net.createConnection({ port: 3000 }, () => {
  console.log('Connected to server');
  client.write('Hello server');
});

client.on('data', (data) => {
  console.log('Server says:', data.toString());
  client.end();
}); 

// const elem = document.createElement('p');
    // elem.textContent = `Message from the server: ${event.data}`;
    // document.body.appendChild(elem);