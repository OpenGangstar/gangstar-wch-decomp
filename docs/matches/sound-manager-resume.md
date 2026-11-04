# SoundManager resume

The resume method clears the pause flag, resumes low-FPS music, and
visits populated non-radio slots. It stops music when music is disabled
and resumes slots with paused status. Separate tests for the final radio
flags reproduce the retail branches.

```text
OK  _ZN12SoundManager15resumeAllSoundsEv  0x00352dc9  152 bytes
```
