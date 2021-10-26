import CONFIG from './config';

const API_ENDPOINT = {
  LIST: `${CONFIG.BASE_URL}list`,
  DETAIL: (id) => `${CONFIG.BASE_URL}detail/${id}`,
  REVIEW: `${CONFIG.BASE_URL}review`,
  SEARCH: (query) => `${CONFIG.BASE_URL}search?q=${query}`,
};

export default API_ENDPOINT;
