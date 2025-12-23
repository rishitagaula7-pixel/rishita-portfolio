/* Typing Effect */
const roles = [
  "Computer Science Student",
  "Backend Developer (In Progress)",
  "DSA & LeetCode Practitioner",
  "Aspiring Software Engineer"
];

let roleIndex = 0;
let charIndex = 0;
const typing = document.querySelector(".typing");

function type() {
  if (charIndex < roles[roleIndex].length) {
    typing.textContent += roles[roleIndex][charIndex];
    charIndex++;
    setTimeout(type, 80);
  } else {
    setTimeout(erase, 1500);
  }
}

function erase() {
  if (charIndex > 0) {
    typing.textContent = roles[roleIndex].substring(0, charIndex - 1);
    charIndex--;
    setTimeout(erase, 50);
  } else {
    roleIndex = (roleIndex + 1) % roles.length;
    setTimeout(type, 300);
  }
}

type();

/* Scroll Animation */
window.addEventListener("scroll", () => {
  document.querySelectorAll(".reveal").forEach(section => {
    const top = section.getBoundingClientRect().top;
    if (top < window.innerHeight - 100) {
      section.classList.add("active");
    }
  });
});
