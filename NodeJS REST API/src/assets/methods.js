const { default: axios } = require("axios");

const options = {
  timeout: 5000,
};

class methods {
  async request(ip, file) {
    const url = this.getUrl(ip, file);

    const result = await axios.get(url, options);
    if (result.status === 200) return result.data;
    else throw new Error(`Error: ${result.status}`);
  }

  getUrl(ip, file) {
    if (!ip.startsWith("http://")) return `http://${ip}/${file}`;
    else return ip + "/" + file;
  }

  getIp(ip) {
    if (ip.startsWith("https") || ip.startsWith("http")) return ip.split("/")[2];
    else return ip.split("/")[0];
  }
}

module.exports = new methods();
