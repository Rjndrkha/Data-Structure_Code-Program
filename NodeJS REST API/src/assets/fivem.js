const mehtods = require("./methods");

class fivemApi {
  constructor(ip) {
    if (!ip) throw new Error("IP address is required");

    if (typeof ip != "number" && typeof ip != "string") throw new Error("IP address must be a string or number");

    if (typeof ip != "string") this.ip = ip.toString();

    this.ip = ip;
  }

  async getAllInfo() {
    const data = await mehtods.request(this.ip, "info.json");
    if (data) data.urlConnection = this.getUrlConnection(); // add url connection
    delete data.icon;
    data.players = await mehtods.request(this.ip, "players.json");
    if (data.players.length > 10) {
      data.players = [];
    } else {
      data.players = await mehtods.request(this.ip, "players.json");
    }
    return data; // return object
  }

  getUrlConnection() {
    return `https://fivem://connect/${mehtods.getIp(this.ip)}`;
  }

  async getName() {
    const data = await this.getAllInfo();
    return data.server; // return string
  }

  async getResources() {
    const data = await this.getAllInfo();
    return data.resources; // return array
  }

  async getIcon() {
    const data = await this.getAllInfo();
    return data.icon ? `data:image/png;base64,${data.icon}` : ""; // return buffer
  }

  async getBanner_connecting() {
    const data = await this.getAllInfo();
    return data.vars.banner_connecting; // return url
  }

  async getBanner_detail() {
    const data = await this.getAllInfo();
    return data.vars.banner_detail; // return url
  }

  //- players

  async getPlayers() {
    const data = await mehtods.request(this.ip, "players.json");
    return data; // return array
  }

  async getPlayersCount() {
    const data = await this.getPlayers();
    if (data) return data.length; // return number
  }
}

module.exports = fivemApi;
