const video = document.querySelector('video');
const progressRange = document.querySelector('.progress-range');
const progressBar = document.querySelector('.progress-bar');
const playBtn = document.getElementById('play-btn');
const volumeIcon = document.getElementById('volume-icon');
const volumeRange = document.querySelector('.volume-range');
const volumeBar = document.querySelector('.volume-bar');
const currentTime = document.querySelector('.time-elapsed');
const duration = document.querySelector('.time-duration');
const playerSpeed = document.getElementById('player-speed');
const fullscreenBtn = document.getElementById('fullscreen-btn');
const player = document.querySelector('.player');

// Play/Pause -----------------------------------------------

function showPlayBtn() {
    playBtn.classList.replace('fa-pause', 'fa-play');
    playBtn.setAttribute('title', 'Play');
}

function togglePlay() {
    if (video.paused) {
        video.play();
        playBtn.classList.replace('fa-play', 'fa-pause');
        playBtn.setAttribute('title', 'Pause');
    }

    else {
        video.pause();
        showPlayBtn();
    }
}

// On Video End

video.addEventListener('ended', showPlayBtn);

// Progress Bar ------------------------------------------------

// Calculate and Show Current Time

function displayTime(time, videoDuration) {
    let min = Math.floor(time / 60);
    let sec = Math.floor(time % 60);
    let durationMin = Math.floor(videoDuration / 60);
    let durationSec = Math.floor(videoDuration % 60);

    sec = sec > 9 ? sec : `0${sec}`;

    durationSec = durationSec > 9 ? durationSec : `0${durationSec}`;

    currentTime.textContent = `${min}:${sec}`;
    duration.textContent = `${durationMin}:${durationSec}`;
}

// Update Progress Bar as Video Plays

function updateProgress() {
    const width = (video.currentTime / video.duration)*100
    progressBar.style.width = `${width}%`;
    displayTime(video.currentTime, video.duration);
}

// Click to Seek within Video

function setProgress(e) {
    const newTime = (e.offsetX / progressRange.offsetWidth);
    progressBar.style.width = `${newTime * 100}%`;
    video.currentTime = newTime * video.duration;
    // console.log(e);
}

// Change Volume ---------------------------------------------

let lastVolume = 1;

// On Click change Volume

function changeVolumeIcon(newVolume) {
    volumeIcon.className = '';
    if ( newVolume > 0.6 ) {
        volumeIcon.classList.add('fas', 'fa-volume-up');
    }
    
    else if ( newVolume < 0.6 && newVolume > 0 ) {
        volumeIcon.classList.add('fas', 'fa-volume-down');
    }
    
    else if ( newVolume === 0 ) {
        volumeIcon.classList.add('fas', 'fa-volume-off');
    }
}

function changeVolume(e) {
    // console.log(e);
    let newVolume = (e.offsetX / volumeRange.offsetWidth);
    if (newVolume < 0.1) {
        newVolume = 0;
    }
    
    if (newVolume > 0.9) {
        newVolume = 1;
    }
    volumeBar.style.width = `${newVolume * 100}%`;
    video.volume = newVolume;
    
    // Change Volume Icon Depending Upon Volume Level
    changeVolumeIcon(newVolume);
    
    lastVolume = newVolume;
}

// Mute Toggle Function

function toggleMute() {
    volumeIcon.className = '';
    if ( video.volume ) {
        lastVolume = video.volume;
        video.volume = 0;
        volumeBar.style.width = '0%';
        volumeIcon.classList.add('fas', 'fa-volume-mute');
        volumeIcon.setAttribute('title', 'Unmute');
    }
    
    else {
        video.volume = lastVolume;
        volumeBar.style.width = `${lastVolume * 100}%`;
        volumeIcon.setAttribute('title', 'Mute');
        changeVolumeIcon(lastVolume);
    }
}

// Set Player Speed ---------------------------------------------

// On Change Set Player Speed
function setPlayerSpeed() {
    video.playbackRate = playerSpeed.value;
}

/* View in fullscreen */

function openFullscreen(elem) {
    if (elem.requestFullscreen) {
        elem.requestFullscreen();
    } else if (elem.webkitRequestFullscreen) { /* Safari */
        elem.webkitRequestFullscreen();
    } else if (elem.msRequestFullscreen) { /* IE11 */
        elem.msRequestFullscreen();
    }
}

/* Close fullscreen */

function closeFullscreen() {
    if (document.exitFullscreen) {
        document.exitFullscreen();
    } else if (document.webkitExitFullscreen) { /* Safari */
        document.webkitExitFullscreen();
    } else if (document.msExitFullscreen) { /* IE11 */
        document.msExitFullscreen();
    }
}

// Toggle Fullscreen -------------------------------------------

let fullscreen = false;

function toggleFullscreen() {
    if (!fullscreen) {
        fullscreen = true;
        openFullscreen(player);
        fullscreenBtn.classList.replace('fa-expand', 'fa-compress');
        fullscreenBtn.setAttribute('title', 'Exit Fullscreen');
        video.classList.add('video-fullscreen');
    }
    else {
        closeFullscreen();
        fullscreen = false;
        fullscreenBtn.classList.replace('fa-compress', 'fa-expand');
        fullscreenBtn.setAttribute('title', 'Enter Fullscreen');
        video.classList.remove('video-fullscreen');
    }
}

// Event Listeners -----------------------------------------------

playBtn.addEventListener('click', togglePlay);
video.addEventListener('click', togglePlay);
video.addEventListener('timeupdate', updateProgress);
video.addEventListener('canplay', updateProgress);
progressRange.addEventListener('click', setProgress);
volumeRange.addEventListener('click', changeVolume);
volumeIcon.addEventListener('click', toggleMute);
playerSpeed.addEventListener('change', setPlayerSpeed);
fullscreenBtn.addEventListener('click', toggleFullscreen);
